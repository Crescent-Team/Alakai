local serde = require("@lune/serde")
local fs = require("@lune/fs")
local process = require("@lune/process")

local info = serde.decode("json", fs.readFile("buildInfo.json"))

local executableInfo = info.executable
local files = executableInfo.exeFiles

for _, depString in string.split(executableInfo.dependencies, " ") do
    files ..= " "
    files ..= info.libraries[depString]
end

local args = string.split(files, " ")
table.insert(args, `-o{executableInfo.name}`)
table.insert(args, "-O2")
print(process.spawn("gcc", args).stderr)