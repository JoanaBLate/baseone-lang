// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

"use strict"

// TODO: make all tests for nodejs

const fs = require("node:fs")
const process = require("node:process")


function getCurrentWorkingDirectory() {
    return __dirname
}

function getCliOptions() {
    return process.argv.slice(2) // cloning
}

function readBaseOneFolder(folderName, tokenImport) {
    let elements = [ ]
    try {
        elements = fs.readdirSync(folderName)
    }
    catch(__e) {
        error(tokenImport, "could not read folder/package: " + folderName)
    }
    const baseOnePaths = [ ]
    for (const element of elements) { 
        const path = folderName + pathSeparator + element
        const stats = fs.statSync(path)
        if (stats.isDirectory()) { cliError("found folder inside folder: " + path) }
        if (! stats.isFile()) { continue }
        if (path.endsWith(".b")) { baseOnePaths.push(path); continue }
        if (path.toLowerCase().endsWith(".b")) { 
            cliError("found uppercase letter in filename extension: " + path)
        }        
    }
    return baseOnePaths
}

function readTextFile(path) {
    try {
        return fs.readFileSync(path, "utf8")
    } 
    catch (__err) {
        cliError("could not read file: " + path)
    }
}

function writeCFile(text) {
    const path = destinyCFilename + ".c"
    assureWritingCFileIsSafe(path)
    try {
        fs.writeFileSync(path, text)
    }
    catch (__err) {
        cliError("could not write file: " + path)
    }
}

function assureWritingCFileIsSafe(path) {
    let text = ""
    try {
        text = fs.readFileSync(path, "utf8")
    }
    catch (__err) {
        return // there is no file
    }
    if (text.startsWith(generatedWarning)) { return }
    cliError("aborting due to the risk of overwriting this non-generated file: " + path)
}

function exitProgram() {
    process.exit(0)
}

