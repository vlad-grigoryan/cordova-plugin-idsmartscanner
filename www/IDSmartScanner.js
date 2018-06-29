var exec = require('cordova/exec');

exports.scan = function (arg0, success, error) {
    exec(success, error, "IDSmartScanner", "scan", [arg0]);
};

exports.echojs = function(arg0, success, error) {
    if (arg0 && typeof(arg0) === 'string' && arg0.length > 0) {
        success(arg0);
    } else {
        error('Empty message!');
    }
};

