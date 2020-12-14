const http = require('http');
const app = require('./app')

// assigning a port number 
const port = process.env.PORT || 3000;

// creating a server 
const server = http.createServer(app);

// starting the server on the assigned port
server.listen(port);