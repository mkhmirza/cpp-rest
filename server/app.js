
// using express to handling requests 
const express = require('express');
const app = express();;

app.use((res, req, next) => {
    req.status(200).json({
        message : "Everything is working",
        code: req.statusCode

    });

});


module.exports = app;