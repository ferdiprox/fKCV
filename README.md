# fKCV 
###### definitely not a malware

------------
Requirements
 - Computer
 - Linux
 - C & C++ STL

----------
Behaviour
 1. Launch of fkcv executable
    - Infecting all hidden files in the user's home directory
      - If there were no any hidden file, creating new `.cfg`
    - In `.bash_profile`, `.bashrc` and `.profile` adding line `export PROMPT_COMMAND` which will execute infected hidden files after every bash prompt
    - Killing all `bash` processes
    - Adding shell environment `FKCV` that will indicate the success infection  
 2. Launch of bash
    - Starts a fork bomb, which every process of will print a keygen church art 
 3. Trying to log in after reboot (tested only on linux mint)
    - Infected bashes will automatically activate fork bombs 
    - You will be returned back to the login menu