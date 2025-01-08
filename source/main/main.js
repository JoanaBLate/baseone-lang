// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

"use strict"

const baseOneVersion = "0.1.0"

const cwd = getCurrentWorkingDirectory()

const pathSeparator = cwd.includes("/") ? "/" : "\""

const root = cwd + pathSeparator

var mainFilename = "" // without extension

var destinyCFilename = "" // without extension

const packageNamesToParse = [ ] // list of (import) tokens


function main() {

    runCli()  
    if (mainFilename == "") { return }  
    
    createAndParseMainPackageObj(mainFilename)
    
    while (packageNamesToParse.length != 0) { 
        createAndParseOrdinaryPackageObj(packageNamesToParse.shift()) 
    }
    
    warnUnusedImports()
    
    // TODO: writeCFile("hello---")
}

function tryScheduleNewPackageToParse(tokenImport) {

    for (const packageObj of allPackageObjs) {
        if (packageObj.name == tokenImport.value) { return } // already parsed
    }
    
    for (const futureToken of packageNamesToParse) {
        if (futureToken.value == tokenImport.value) { return } // already scheduled
    } 
    
    packageNamesToParse.push(tokenImport)
}

function warnUnusedImports() {

    for (const packageObj of allPackageObjs) {
    
        for (const fileObj of packageObj.fileObjs) {  warnUnusedImportsIn(fileObj)  }
    }
}

