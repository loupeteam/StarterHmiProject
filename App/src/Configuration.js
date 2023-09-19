//TODO: Read the configuration from a file
var Configuration = new WEBHMI.HMI(() => {

})

Configuration.port = 8000;
Configuration.ipAddress = '127.0.0.1';
Configuration.cncFolder = 'WebHMI'; 

export {Configuration};