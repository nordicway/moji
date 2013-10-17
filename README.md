## MOJI

MOJI is an unofficial client for the MOSS plagiarism detection service,
written in Java.
It has the following key features:

- Pure Java implementation with few dependencies
- Cross-platform support

## Requirements

Java 6 or better

## Installation

Either

- download the JAR or
- build it yourself using Maven.

Then include it in your Java project.

## Quick Start

### 1. Preparation

MOJI requires some kind of MOSS-compatible directory structure to distinguish
between different students.

To achieve this, copy all student source codes to a directory where each
subdirectory contains the source code of a single student.

A valid directory containing student solutions might look like this:


	solution_directory
	|- student1
	   |- classA.java
	   |- ...
	|- student2
	   |- ...
	|_ student3
	   |- ...

### 2. Download the JAR (or build it yourself) and include it in your project.

### 3. Create a new socket client object to communicate with the MOSS server.

## Example code

	import java.io.File;
	import java.util.List;
	import java.net.URL;

	public class QuickStart {
		public static void main(String[] args) throws Exception {
			//a list of students' source code files located in the prepared
			//directory.
			
			//List<File> files = ...;
			
			//get a new socket client to communicate with the MOSS server
			//and set its parameters.
			SocketClient socketClient = new SocketClient();
			
			//set your MOSS user ID
			socketClient.setUserID("123456789");
			//socketClient.setOpt...
			
			//set the programming language of all student source codes
			socketClient.setLanguage("java");
			
			//initialize connection and send parameters
			socketClient.run();
			
			//upload all source files of students
			for (File f : files) {
				socketClient.uploadFile(f);
			}
			
			//finished uploading, tell server to check files
			socketClient.sendQuery();
			
			//get URL with MOSS results and do something with it
			URL results = socketClient.getResultURL();
			System.out.println("Results available at " + results.toString());
		}
	}

## Tests

To execute all tests, simply run

	mvn test

## Documentation

<a href="http://www.zielke.it/moji/">http://www.zielke.it/moji/</a>

## Attribution

This software communicates with MOSS by Alex Aiken of Stanford University.
MOJI is not in any way affiliated with MOSS.

## License

MOJI is under MIT License. Please see the corresponding license files.