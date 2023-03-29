class dropDownControl extends viewDelegate{
    constructor(){
        super()
    }
    willOpen(){

    }
}

class CncController extends dropDownControl{
    constructor(){
        super()
        this.files = 10
        machine.initCyclicRead('HMI_CNC_Co:FileBrowser')
        setInterval(()=>{
            if( machine['HMI_CNC_Co:FileBrowser']?.NumFiles ){
                if( this.files != machine['HMI_CNC_Co:FileBrowser'].NumFiles)
                {
                    this.files = machine['HMI_CNC_Co:FileBrowser'].NumFiles
                    this.updateDom()
                }        
            }
        }, 1000)
    }
    open(  ){

    }
    willUpdate(){
        this.files = machine['HMI_CNC_Co:FileBrowser']?.NumFiles || 0
    }
    willLoad(){
        this.files = machine['HMI_CNC_Co:FileBrowser']?.NumFiles || 0
    }
}

class componentState extends viewDelegate{
    constructor(){
        super()
        this.value = {value: 10};
    }
}

var state = new componentState()
var state2 = {
    value:{value:2}
}

function decrementState2( obj, key, value ){
    state2.value.value += (value*10)
}

function incrementState2( obj, key, value ){
    state2.value.value += (value*10)    
}
