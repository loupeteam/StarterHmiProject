
var machine = new WEBHMI.Machine({
  port: 8000,
  ipAddress: '127.0.0.1',
  maxReconnectCount: 5000
});

let serviceAxis = {}
import('./axisController.js').then(ns => {
  Object.assign(window, ns);
  serviceAxis = new axisController(0, 12)
});

setInterval(WEBHMI.updateHMI, 30)

var Configuration = new WEBHMI.HMI(() => {

})

Configuration.ipAddress = '127.0.0.1';
Configuration.cncFolder = '[TODO]';
// configuration.getReadList = machine.getReadList;