/* Will accept and reply to network communications
 *
 * Paul Geromini
 *
 */

import java.net.*;
import java.io.*;

public class myserver {

    public static void main(String[] args) {

	System.out.println("I am waiting for a request, send one.");

	ServerSocket socket;
	Socket client;

	PrintStream output;
	BufferedReader input; 

	try {
	    //Create socket
	    socket = new ServerSocket(Integer.parseInt(args[0])); 

	    //Create a socket listener 
	    client = socket.accept(); 

            //open input and output streams
	    input = new BufferedReader(new InputStreamReader(client.getInputStream())); 
	    output = new PrintStream(client.getOutputStream()); 

	    //Wait for requests
	    while(true){
                String response; 
                response = input.readLine();
		//GET request
		if (response.indexOf("GET") != -1){
		    output.println("200 OK close");
		    System.out.println("Communications Closed - GET"); 
		    break;
		} else if (response.indexOf("PUT") != -1){
		    //PUT request
		    //Save text to file
		    BufferedWriter out = new BufferedWriter(new FileWriter("NEWFILE.txt"));

		    //Remove put from Response
		    String writeToFile = response.substring(3); 
		    out.write(writeToFile); 
		    out.close(); 

                    output.println(response);
		    output.println("200 OK File Created close");
		    System.out.println("Communications Closed - PUT");
		    break;
		} else {
		    //Unrecognized request 
		    output.println("400 BAD REQUEST");
		    System.out.println("Communication Closed - Bad Request");
		    break;
		}
	    }
	    //Close everything
	    output.close();
	    input.close();
	    client.close();
	    socket.close();

	}
	catch(IOException e) {
	    System.out.println("I could not create a socket, sorry.");
	}
    }
}
