# Named Pipe Task
- create 2 independent programs that perform communication using named pipes. 
- One program will be the client program that will wait for server to send some data via a named pipe. 
<br>  The data sent by the server is as follows:
<br>  Operator operand1 operand2
<br>  The operands can be  **+, -, *, /***  <br>
- The client will then apply the operator on the operands and return the result to server via named pipe. 
- The server will then print the result on the screen

## Example
For example, if the server passed the following to the client: **+ 4 10**, 
<br>then the client will calculate 4+10 and return 14 to server via the pipe. The server will then print it.
