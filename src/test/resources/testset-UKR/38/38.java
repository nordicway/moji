package Introduction;

import java.io.*;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by yaoslav on 23.03.16.
 */

class WriteF {

    private static File file=new File("result.txt");


    public void WriteFile(String name,String matrix){

        //when we put true into FileWriter, we will not be able to rewrite info. It will store in the file

        try (BufferedWriter br = new BufferedWriter(new FileWriter(file,true))) {
            br.write(name);
            br.newLine();
            br.write(matrix);
            br.newLine();
        } catch (IOException e) {
            System.out.println("Unable to read file " + file.toString());
        }
    }
}


public class Main {
    private static int NumVertices;
    private static int NumEdges;

    private static int [] DotBegin=new int[100];
    private static int [] DotEnd=new int[100];

    private static int[][] AdjacencyMatrix;
    private static int[][] IncedenceMatrix;



    public static void main(String[] args) throws FileNotFoundException {
        Main.ReadF();
        WriteF wf = new WriteF();
        wf.WriteFile("Adjacency Matrix", Main.AdjacencyMatrix());
        wf.WriteFile("Incedence Matrix", Main.IncedenceMatrix());

    }

    public static void ReadF() throws FileNotFoundException {
        Scanner sc =new Scanner(new File("graph_01_1.txt"));

        NumVertices=sc.nextInt();
        NumEdges=sc.nextInt();

        int i=0;
        while (sc.hasNext()) {
            DotBegin[i]=sc.nextInt();
            DotEnd[i]=sc.nextInt();
            i++;
        }

    }

    public static String AdjacencyMatrix(){
        String result=new String();

        System.out.println(NumVertices);
        System.out.println(NumEdges);
        AdjacencyMatrix=new int[NumVertices][NumVertices];
        for(int i=0;i<NumEdges;i++){
            AdjacencyMatrix[DotBegin[i]-1][DotEnd[i]-1]=1;
        }

        for(int i=0;i<NumVertices;i++){
            for(int j=0;j<NumVertices;j++){
                result+=AdjacencyMatrix[i][j]+" ";
            }
            result+='\n';
        }
        return result;
    }

    public static String IncedenceMatrix(){
        String result=new String();
        IncedenceMatrix=new int[NumVertices][NumEdges];

        for(int i=0;i<NumEdges;i++){
           if(DotBegin[i]==DotEnd[i])
            IncedenceMatrix[DotBegin[i]-1][i]=2;
            else {
               IncedenceMatrix[DotBegin[i] - 1][i] = -1;
               IncedenceMatrix[DotEnd[i]-1][i]=1;
            }
        }

        for(int i=0;i<NumVertices;i++){
            for(int j=0;j<NumEdges;j++){
                result+=IncedenceMatrix[i][j]+" ";
              //  System.out.print(IncedenceMatrix[i][j]+" ");
            }
            //System.out.println();
            result+='\n';
        }
        return result;
    }


}
