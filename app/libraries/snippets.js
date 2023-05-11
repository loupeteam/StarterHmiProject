/**
 * @author davidblackburn
 * @author Josh
 * @author Scott
 */

 /* Revision history:
  * 0.1.1   Added: replace support for data-include and template-include
  * 0.1.0   Added: template-include, and wait()
  *	0.0.1	Initial Release
  *
  *
  */

window.onload = function() {
    if (!window.jQuery) {  
        throw new Error('Snippets requires jquery');
    }
}

var Snippets = {
    Version : '0.1.0',
    loading: 0,
    callbacks: []
}

// Load js file
Snippets.loadjsfile = function (url) {
    return new Promise(function(resolve, reject) {
        var script = document.createElement("script");
        script.onload = resolve;
        script.onerror = reject;
        script.src = url;
        document.body.appendChild(script);
    });
}

// Loads css file
Snippets.loadcssfile = function (filename){
	var fileref=document.createElement("link");
	fileref.setAttribute("rel", "stylesheet");
	fileref.setAttribute("type", "text/css");
	fileref.setAttribute("href", filename);
	document.body.append(fileref);
}

// Include files into an HTML document
Snippets.includeFiles = function (successCallback) {
    Snippets.loading = 1;
    var unWrapElements = [];
    var finished = function(){
        unWrapElements.forEach(element => {
            element.children().first().unwrap();
        });

        if (successCallback) {
            successCallback(); 
         }	
        Snippets.loading = 0;
        // Snippets.callbacks could be changed to a function that things add to
        // So you call on function instead of going through an array
        // something like this: function joint(a){var b;return b=a[a.length-1],a.pop(),a=a.length>1?joint(a):a[0],function(){b.apply(new a)}}
        while (Snippets.callbacks.length > 0) {
            let popped = Snippets.callbacks.pop();
            if(popped)
                popped();
            else{ //Remove
                console.warn("Snippets finished got a callback that was undefined.");
            }
        }
        
    }

	// Iterate through elements and load external files
	var includeFile = function (index, element, successCallback) {
		$(element).find("[data-include]").each(
			function (index, element) {
				var $this = $(this);
				includeFile.numberFiles++;
				var fileName = $this.attr("data-include");
				console.log("loading " + fileName);
				$this.load(fileName, function (response, status, xhr) {
					includeFile.numberFiles--;
					console.log(fileName + ": " + status);
					if (status == 'error') {
						console.error(fileName + " " + xhr.status + " " + xhr.statusText);
					}
                    includeFile(index, $this, successCallback);
                    if($this.attr("replace"))
                        unWrapElements.push($this);
					if (includeFile.numberFiles == 0) {
                        finished();	
					}
				});
            });
        //Include js files
        $(element).find("[js-include]").each(
            function(index,element) {
                var $this = $(this);
                var filename = $this.attr("js-include");
                // console.log("loading " + filename);
                Snippets.loadjsfile(filename);
            });
        //Include css files
        $(element).find("[css-include]").each(
            function (index, element) {
                var $this = $(this);
                var filename = $this.attr("css-include");
                console.log("loading " + filename);
                Snippets.loadcssfile(filename);
            });
        
        //Add templates to callback list
        $(element).find("template[template-include]").each(
            function(index,element){
                var $this = $(this);
                Snippets.wait(function(){
                    if(!$($this.attr("template-include")).attr("replace"))
                        $($this.attr("template-include")).append($this.html());
                    else
                        $($this.attr("template-include")).replaceWith($this.html());
                    console.log("Moving to " + $this.attr("template-include"));
                })})
	}

	includeFile.numberFiles = 0; //Note: May want to move this to a onProgress callback
	includeFile(0, document, successCallback)
};

// Ques functions to run after all files are included
Snippets.wait = function(callback) {
    return new Promise((resolve, reject) => {
        if (typeof (callback) == "function") {
            var modifiedCallback = function(){
                resolve(callback());
            }
            if (Snippets.loading)
                Snippets.callbacks.push(modifiedCallback);
            else
                modifiedCallback();
        }
        else 
            reject("arg is not a function");
    })
    
}