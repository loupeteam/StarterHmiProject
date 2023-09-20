import { saveAs } from '../libraries/FileSaver.js';

var Configuration = new WEBHMI.HMI(() => {

})

//Set the default configuration
Configuration.port = 8000;
Configuration.ipAddress = '127.0.0.1';
Configuration.cncFolder = 'WebHMI';

//create a new promise to return
let configurationLoaded = new Promise((resolve, reject) => {
    //Make an asynchronous xmlhttprequest to read the configuration file
    let request = new XMLHttpRequest();
    request.onreadystatechange = function () {
        if (request.readyState === 4 ){
            if(request.status === 200 || request.status === 0) {

                let configurationText = getActiveConfiguration(request.responseText);

                //Read the datas
                Configuration = Object.assign(Configuration, JSON.parse(configurationText))
                resolve(Configuration);
            }
            else {
                resolve(Configuration);
            }
        }
    }
    request.open('GET', '../OpenRobot.json', true);
    request.send(null);
});

//Create a function to read the configuration
Configuration.writeVariable = function (name, value) {
    Configuration.value(name, value);
    ConfigurationChanged();
};

//Create a function to read the configuration
//  This function compares the file contents to the local storage contents
//  If they are the same, it returns the local storage contents
//  Otherwise it returns the file contents and updates the local storage contents
function getActiveConfiguration( filecontents ) {
    let localStorageContent = window.localStorage.getItem('ConfigurationFileContents');
    if (filecontents && localStorageContent && filecontents === localStorageContent) {
        return localStorage.getItem('Configuration');
    }
    else{
        window.localStorage.setItem('ConfigurationFileContents', filecontents);    
        return filecontents;
    }
}

//Create a function to write the configuration
//  This function writes the configuration to the local storage
//  It also writes the configuration to the file
//  This function is called whenever the configuration is changed
function ConfigurationChanged() {
    localStorage.setItem('Configuration', JSON.stringify(Configuration))
}

//Create a function to export the configuration
//  This function exports the configuration to a file
//  It is also added to the window object so it can be called from the console
function exportConfiguration(){
    let configurationText = JSON.stringify(Configuration);
    let blob = new Blob([configurationText], {type: "text/plain;charset=utf-8"});
    saveAs(blob, "OpenRobot.json");
}

//Export the API
export { configurationLoaded, ConfigurationChanged, exportConfiguration};