// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

"use strict"

var shallClearScreen = false

function runCli() {
    const options = getCliOptions() // cloned
    if (options.length == 0) { showOpenMessage(); return; }

    const filename = options.shift()     
    if (filename.startsWith("--")) { cliError("missing file name or file name starts like option: " + filename) }
    if (filename.toLowerCase().endsWith(".bo")) { cliError("unnecessary '.bo' extension: " + filename) }
    mainFilename = filename  
    
    while (options.length != 0) {    
        const option = options.shift()
        if (option == "--clearscreen") { checkOptionClearScreen(); continue }
        if (option.startsWith("--name")) { checkOptionCName(option); continue }        
        cliError("unknown option: " + option)
    }
    
    if (shallClearScreen) { console.log("\u001Bc") }
    
    if (destinyCFilename == "") { destinyCFilename = filename }
}

function checkOptionClearScreen() {
    if (shallClearScreen) {  cliError("repeating option '--clearscreen'") }
    shallClearScreen = true
}

function checkOptionCName(option) {
    if (! option.startsWith("--name=")) { cliError("missing '=' immediately after '--name'") }
    
    const name = option.replace("--name=", "")
    if (name == "") { cliError("missing name immediately after '--name='") }
    
    let count = 0
    const valids = "_-0123456789abcdefghijklmnopqrstuvwxyz"
    for (const c of name.toLowerCase()) {
        if (! valids.includes(c)) { cliError("bad value for option: " + option) }
        if (c == "_"  ||  c == "-") { count += 1 }
    }
    if (count == name.length) {  cliError("bad value for option: " + option) }
    
    if (destinyCFilename != "") { cliError("repeating option '--name'") }
    
    destinyCFilename = name
}
        
function showOpenMessage() {
    console.log("")
    console.log(" BaseOne Transpiler   version", baseOneVersion, "\n")
    console.log("  Transpiles BaseOne files into a single C file\n")
    console.log("  Usage: baseone myFile\n")
    console.log("  Usage: baseone myFile --name=myOtherName --clearscreen\n")
    console.log("  Note: don't write the '.bo' extension\n")
    console.log("  Help: https://github.com/JoanaBLate/baseone-lang\n") // TODO: fix the address
}

function cliError(msg) {
    console.log("ERROR:", msg)
    exitProgram()
}

