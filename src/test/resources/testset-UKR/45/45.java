import java.io.*;

public class Main {

    static int v,e;
    static int[][] sum,inc;
    static boolean isConsoleOutputSelected;
    static boolean isExitRequested;

    public static void main(String[] args) {
        try {
            System.out.println("developed by Ryabtsev IS-51");

            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

            do {
                System.out.println("Enter input file path");
                readFileAndFillArrays(reader.readLine());

                System.out.println("\nProcessed.\n");
                System.out.println(" [1] - console output, else - file output");
                isConsoleOutputSelected = Integer.parseInt(reader.readLine()) == 1;

                if (isConsoleOutputSelected) {
                    consoleOutput();
                } else {
                    System.out.println("Enter output file path");
                    fileOutput(reader.readLine());
                }

                System.out.println(" [1] - restart program, else - close program");
                isExitRequested  = Integer.parseInt(reader.readLine()) == 1;
            } while (isExitRequested);


            reader.close();
        } catch (Exception ex){ex.printStackTrace();}
    }

    public static void initZeroArrays(int v, int e){
        sum = new int[v][v];
        inc = new int[v][e];

        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                sum[i][j] = 0;
            }
            for (int j = 0; j < e; j++) {
                inc[i][j] = 0;
            }
        }
    }

    public static void readFileAndFillArrays(String path) throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(path)));
        String[] firstLine = reader.readLine().split(" ");
        v = Integer.parseInt(firstLine[0]);
        e = Integer.parseInt(firstLine[1]);

        initZeroArrays(v, e);
        int x,y;

        for (int i = 0; i < e; i++) {
            firstLine = reader.readLine().split(" ");
            x = Integer.parseInt(firstLine[0])-1;
            y = Integer.parseInt(firstLine[1])-1;

            sum[x][y] = 1;

            if (x!=y) {
                inc[x][i] = -1;
                inc[y][i] = 1;
            } else inc[x][i]=2;
        }

        reader.close();
    }

    public static void fileOutput(String path) throws IOException{
        FileWriter writer = new FileWriter(path);

        writer.write("     ");
        for (int j = 0; j < v; j++) {
            writer.write(((j+1)<10?" ":"")+"v"+(j+1)+" ");
        }
        writer.write('\n');
        for (int i = 0; i < v; i++) {
            writer.write(((i+1)<10?" ":"")+"v"+(i+1)+" ");
            for (int j = 0; j < v; j++) {
                writer.write("  "+sum[i][j]+" ");
            }
            writer.write('\n');
        }


        writer.write('\n');
        writer.write('\n');
        writer.write('\n');

        writer.write("     ");
        for (int j = 0; j < e; j++) {
            writer.write(((j+1)<10?"  ":((j + 1) < 100 ? " ":""))+"e"+(j+1)+" ");
        }
        writer.write('\n');
        for (int i = 0; i < v; i++) {
            writer.write(((i+1)<10?" ":"")+"v"+(i+1)+" ");
            for (int j = 0; j < e; j++) {
                writer.write((inc[i][j]>=0?"   ":"  ")+inc[i][j]+" ");
            }
            writer.write('\n');
        }


        writer.close();
    }

    public static void   consoleOutput(){


        System.out.print("     ");
        for (int j = 0; j < v; j++) {
            System.out.print(((j + 1) < 10 ? " " : "") + "v" + (j + 1) + " ");
        }
        System.out.println();
        for (int i = 0; i < v; i++) {
            System.out.print(((i + 1) < 10 ? " " : "") + "v" + (i + 1) + " ");
            for (int j = 0; j < v; j++) {
                System.out.print("  " + sum[i][j] + " ");
            }
            System.out.println();
        }


        System.out.println();
        System.out.println();
        System.out.println();


        System.out.print("     ");
        for (int j = 0; j < e; j++) {
            System.out.print(((j + 1) < 10 ? "  " : ((j + 1) < 100 ? " ":"")) + "e" + (j + 1) + " ");
        }
        System.out.println();
        for (int i = 0; i < v; i++) {
            System.out.print(((i + 1) < 10 ? " " : "") + "v" + (i + 1) + " ");
            for (int j = 0; j < e; j++) {
                System.out.print((inc[i][j] >= 0 ? "   " : "  ") + inc[i][j] + " ");
            }
            System.out.println();
        }

    }
}
