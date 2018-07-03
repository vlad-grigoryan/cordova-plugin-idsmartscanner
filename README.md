# Cordova Plugin IDSmartScanner for iOS
================================

For developing plugin those repositories were used as examples:
* https://github.com/dynamsoft-dbr/cordova-plugin-dbr
* https://github.com/ModusCreateOrg/cordova-plugin-example

The plugin is based on third party custom framework provider by [IDScan Biometrics Ltd](https://www.idscan.com/).

## Installation
1. Install **Cordova** via **npm**:

      ```  
        npm install -g cordova
    ```

2. Download the source code and add the plugin via local path:
    
    ```
        cordova plugin add <local-path>/cordova-plugin-idsmartscanner-master
    ```

   Or, install the plugin via repo url directly:
    
    ```
        cordova plugin add https://github.com/ScientificDimension/cordova-plugin-idsmartscanner.git
    ```

### Supported Platforms

- iOS


## Using the plugin ##
The plugin creates the object `cordova/plugin/IDSmartScanner` with the method `scan`.

### Example

A full example of `index.js` could be as followed:

```js
var app = {
    initialize: function() {
        document.addEventListener('deviceready', this.onDeviceReady.bind(this), false);
    },
    onDeviceReady: function() {
        this.receivedEvent('deviceready');
    },
    receivedEvent: function(id) {
        var parentElement = document.getElementById(id);
        var listeningElement = parentElement.querySelector('.listening');
        var receivedElement = parentElement.querySelector('.received');

        listeningElement.setAttribute('style', 'display:none;');
        receivedElement.setAttribute('style', 'display:block;');

        console.log('Received Event: ' + id);
        
        alert('start')

        idsmartscanner.scan(
                       {
                       "urlPrefix" : 'put your urlPrefix here', // iOS
                       "username" : 'put your username here', // iOS
                       "password" : 'put your password here' // iOS
                       },
                       function(scanningResult) {
                       
                       alert("We got a scanning result\n" +
                             "Result: " + scanningResult);
                       
                       ///////////////////////////////////////////////////////////////
                       console.log('plugin success: ' + scanningResult)
                       ///////////////////////////////////////////////////////////////
                       
                       },
                       function(scanningResult) {
                       
                       alert("Scanning failed\n" +
                             "credentials: " + scanningResult.credentials + "\n" +
                             "code: " + scanningResult.enterpriseError.code + "\n" +
                             "localizedDescription: " + scanningResult.enterpriseError.localizedDescription + "\n");
                       
                       ///////////////////////////////////////////////////////////////
                       console.log('plugin failure: ' + scanningResult)
                       ///////////////////////////////////////////////////////////////
                       
                       }
                       
                       );
    }
};

app.initialize();

```

### Scanning Result

On `failure` and on `success` plugin returns the same object `scanningResut` which is dictionary with next keys:

* credentialsHasBeenRetrieved
* enterpriseResult
* enterpriseError
* detailResult
* detailError

`Failed` scanning results may be in 2 cases:

1. Credentials has not been provided

```
{
    "credentialsHasBeenRetrieved":  "0",
    "enterpriseResult": "<null>",
    "enterpriseError": "<null>",
    "detailResult": "<null>",
    "detailError": "<null>"
}
```
2. Enterprise error scanning was occur

```
{
    "credentialsHasBeenRetrieved":  "1",
    "enterpriseResult": "<null>",
    "enterpriseError": "<some object>",
    "detailResult": "<null>",
    "detailError": "<null>"
}
```

`Success` scanning results may be in 2 cases:

1. Enterprise result only has been retrieved (most likely)

```
{
    "credentialsHasBeenRetrieved":  "1",
    "enterpriseResult": "<some object>",
    "enterpriseError": "<null>",
    "detailResult": "<null>",
    "detailError": "<some object>"
}
```
2. Enterprise and detail results have been retrieved (least likely)

```
{
    "credentialsHasBeenRetrieved":  "1",
    "enterpriseResult": "<some object>",
    "enterpriseError": "<null>",
    "detailResult": "<some object>",
    "detailError": "<null>"
}
```
