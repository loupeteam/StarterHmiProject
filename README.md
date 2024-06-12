# Info
Library is provided by Loupe  
https://loupe.team  
info@loupe.team  
1-800-240-7042  

# Description
The StarterHmiProject repo provides a Loupe UX-based starter HMI that includes all of the common utilities that most Loupe HMIs need. It is intended to be a good starting point for new applications. Note that this is a template that is intended to be modified after it has been installed. 

# Getting Started

### Installation
To install using the Loupe Package Manager (LPM), run `lpm init` in an empty directory, and when prompted to install an Automation Studio project, select `No`. Then run `lpm install starterhmiproject`. For more information about LPM, see https://loupeteam.github.io/LoupeDocs/tools/lpm.html

### Running the HMI
Perform the following steps:
- If you are not logged in with LPM, navigate to [Getting Started with LPM](https://loupeteam.github.io/LoupeDocs/tools/lpm/getting-started-with-lpm.html#logging-in) and copy the available token to the second line of `/app/.npmrc`, e.g:
```
//npm.pkg.github.com/:_authToken=<TOKEN>
```
If you are working in a private repository, this change can be tracked with git and not be necessary for future installs. If you are working in a public repo it is recommended to skip this step and login to LPM using the link above. 
- Execute `installHMI.cmd` from the `/scripts` folder, to install the HMI.
- You can then execute `runHMI.cmd` from the `/scripts` folder, and this will launch the HMI. 

# Licensing

This project is licensed under the [MIT License](LICENSE).