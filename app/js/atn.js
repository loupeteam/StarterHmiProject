machine.writeVariable("AtnHmi:refreshState", 1);
var systemState;

machine.readVariable("AtnHmi:systemState", function () {

    systemState = JSON.parse(machine["AtnHmi:systemState"])
    systemState.commands = systemState.commands.sort();
    systemState.States = systemState.States.sort();

    let commands = systemState.commands.map(function (t) {
        return `<li class="list-group-item" onclick="selectCommand('${t}')"> ${t} </li>`
    })
    let states = systemState.States.map(function (t) {
        return `<li class="list-group-item" onclick="selectState('${t}')"> ${t} </li>`
    })
    $('#atnCommand').html(commands)
    $('#atnState').html(states)
});

function filterCommand(e){
    var filterCommands;

    filterCommands = (e.value == '') ? systemState.commands : filterItems(systemState.commands, e.value);

    let commands = filterCommands.map(function (t) {
        return `<li class="list-group-item" onclick="selectCommand('${t}')"> ${t} </li>`
    })

    $('#atnCommand').html(commands)
    $('#atnCommandDropDown').addClass("open")
}

function filterState(e){
    var filterStates;
    filterStates = (e.value == '') ? systemState.States : filterItems(systemState.States, e.value);

    let states = filterStates.map(function (t) {
        return `<li class="list-group-item" onclick="selectState('${t}')"> ${t} </li>`
    })

    $('#atnState').html(states)
    $('#atnStateDropDown').addClass("open")
}

function filterItems(arr, query) {
    return arr.filter((el) => el.toLowerCase().includes(query.toLowerCase()));
}

function selectCommand(which) {
    machine.writeVariable("AtnHmi:AtnPLCOpenCall[0].Command", which);
}

function selectState(which) {
    machine.writeVariable("AtnHmi:readState[0].State", which);
}