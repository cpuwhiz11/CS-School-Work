/* Client Connects to a server and retrives a file via HTTP GET and
 * will execute a HTTP put.
 *
 * Paul Geromini 01056543
 *
 */

import java.io.*;
import java.net.*;

public class myclient {

    private static String readFile(String fileName){
	File file = new File(fileName);
	char[] buffer = null;
	String senderString; 

	try {
	    BufferedReader bufferedReader = new BufferedReader(new FileReader(file));
	    buffer = new char[(int)file.length()];
	    
	    int place = 0;
	    int chars = bufferedReader.read();
	    
	    while (chars != -1){
		buffer[place++] = (char)chars;
		chars = bufferedReader.read();
	    }
	    
	    //place into senderString
	    senderString = new String(buffer); 
	    return senderString; 
	
	} catch (FileNotFoundException e){
	    System.out.println("File was not found");
	} catch (IOException e){
	    System.out.println("Read error occured"); 
	}

	return "ERROR READING"; 
	
    }

    public static void get ( String[] args ){
	System.out.println("Attempting GET Request");

	//Declare variables
        Socket MySocket ;
	BufferedReader input ;
        DataOutputStream output ;

        String response;

	try {
            //Open a socket
	    MySocket = new Socket(args[0], Integer.parseInt(args[1])); 

	    //Create stream to receive server responses.
	    input = new BufferedReader(new InputStreamReader(MySocket.getInputStream())); 
	    
	    //Create an ouptut stream to send messages to server.
	    output = new DataOutputStream(MySocket.getOutputStream()); 
           
	    //Create Request 
	    output.writeBytes("GET /" + args[3] + " HTTP/1.0\n");
       	    output.writeBytes("Host: " + args[0] + "\n");
	    output.writeBytes("\n"); 

            //Read until response
            while( (response = input.readLine()) != null ){
		System.out.println("Response: " + response);
	        if(response.indexOf("close") != -1) {
		    break;
	        }
	    }

	    //close the sockets
	    output.close();
	    input.close();
	    MySocket.close();

	}

	catch(IOException e){
	    System.out.println("I could not initialize the socket correctly." + e);
	}

    }

    //I split PUT and GET even though they could be made generic enough
    //to fit into one function (thus reducing code) because it was helpful
    //to me to see the differences between the two. 
    public static void put ( String[] args ){
	System.out.println("Attempting PUT Reqeust");

	//Declare variables
        Socket MySocket ;
	BufferedReader input ;
        DataOutputStream output ;

        String response;
	String senderString;

	try {
            //Open a socket
	    MySocket = new Socket(args[0], Integer.parseInt(args[1])); 

	    //Create stream to receive server responses.
	    input = new BufferedReader(new InputStreamReader(MySocket.getInputStream())); 
	    
	    //Create an ouptut stream to send messages to server.
	    output = new DataOutputStream(MySocket.getOutputStream()); 
        
            //Read file into string for transfer
            senderString = readFile(args[3]);
           	
	    //Create Request
       	    output.writeBytes("PUT " + senderString + "\n"); 
       	    output.writeBytes("\n"); 

            //Read until response
            while( (response = input.readLine()) != null ){
		System.out.println("Response: " + response);
	        if(response.indexOf("close") != -1) {
		    break;
	        }
	    }

	    //close the sockets
	    output.close();
	    input.close();
	    MySocket.close();
	}

	catch(IOException e){
	    System.out.println("I could not initialize the socket correctly." + e);
	}
    }

    public static void main ( String[] args ) {

        //Determine what kind of operation, GET or PUT
	if( args[2].compareToIgnoreCase("GET") == 0){
	    //call GET function
	    get(args);
	} else {
	    //call PUT function
	    put(args);
	}

    }

}
