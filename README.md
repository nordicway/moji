## MOJI

MOJI is an unofficial Java client for the
 <a href="http://theory.stanford.edu/~aiken/moss/">Moss</a> plagiarism detection
  service.
It has the following key features:

- Pure Java implementation with few dependencies
- Cross-platform support

## Requirements

- Java 6 or better
- Apache Commons IO 2.3

## Installation

Use either of the following methods to obtain a MOJI binary.

- add as Maven dependency:

		<dependency>
			<groupId>it.zielke</groupId>
			<artifactId>moji</artifactId>
			<version>1.0.2</version>
		</dependency>


- download the JAR and include it in your Java project.

- build it yourself using Maven and include the JAR in your Java project.

## Quick Start

### 1. Preparation

MOJI requires some kind of Moss-compatible directory structure to distinguish
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

### 3. Create a new socket client object to communicate with the Moss server.

## Example code

	import java.io.File;
	import java.util.Collection;
	import java.net.URL;
	import org.apache.commons.io.FileUtils;
	import it.zielke.moji.SocketClient;
	
	public class QuickStart {
		public static void main(String[] args) throws Exception {
			// a list of students' source code files located in the prepared
			// directory.
			Collection<File> files = FileUtils.listFiles(new File(
				"C:\\temp\\solution_directory"), new String[] { "java" }, true);

			// a list of base files that was given to the students for this
			// assignment.
			Collection<File> baseFiles = FileUtils.listFiles(new File(
				"C:\\temp\\base_directory"), new String[] { "java" }, true);
			
			//get a new socket client to communicate with the Moss server
			//and set its parameters.
			SocketClient socketClient = new SocketClient();
			
			//set your Moss user ID
			socketClient.setUserID("123456789");
			//socketClient.setOpt...
			
			//set the programming language of all student source codes
			socketClient.setLanguage("java");
			
			//initialize connection and send parameters
			socketClient.run();
			
			// upload all base files
			for (File f : baseFiles) {
				socketClient.uploadBaseFile(f);
			}
			
			//upload all source files of students
			for (File f : files) {
				socketClient.uploadFile(f);
			}
			
			//finished uploading, tell server to check files
			socketClient.sendQuery();
			
			//get URL with Moss results and do something with it
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

This software communicates with
 <a href="http://theory.stanford.edu/~aiken/moss/">Moss</a> by Alex Aiken of
  Stanford University.
MOJI is not in any way affiliated with Moss.

## License

MOJI is under MIT License. Please see the corresponding license files.