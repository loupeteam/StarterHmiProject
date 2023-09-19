//Load the configuration file and start the connection
import('./Configuration.js').then(module => {
  window['Configuration'] = module.Configuration;
  createNewConnection(Configuration.ipAddress, Configuration.port)  
})

const num_axes = 3
import('./axisController.js').then(ns => {
  Object.assign(window, ns);
  //Setup the axis controller for the correct number of axes
  window['serviceAxis'] =  new axisController(0, num_axes);
});

//Create a new connection to the machine
function createNewConnection(ip, port){
  window['machine'] = new WEBHMI.Machine({
    port: port,
    ipAddress: ip,
    maxReconnectCount: 5000
  });
}

//Setup the HMI refresh
setInterval(WEBHMI.updateHMI, 30)


