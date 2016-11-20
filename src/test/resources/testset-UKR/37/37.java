
package Laba1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Created by nelya on 25.02.16.
 */
public class WorkWithFile {

    public static int n, m; //РєРѕР»РёС‡РµСЃС‚РІРѕ РІРµСЂС€РёРЅ Рё СЂРµР±РµСЂ
    public static int[] beginning;
    public static int[] ending;
    public static int[][] adjacencyMatrix;
    public static int[][] incidenceMatrix;
    public static String fileName;
    public static Scanner sc;

    public WorkWithFile(String fileName) {
        this.fileName = fileName;
        try {
            this.sc = new Scanner(new File(fileName));
        } catch (FileNotFoundException e) {
            System.out.println(e);
        }
    }

    public void ReadFile() {
        /*//home//nelya//IdeaProjects//graph_01_2.txt*/
        n = sc.nextInt();
        m = sc.nextInt();
        System.out.println("Number of vertices = " + n); //РєРѕР»РёС‡РµСЃС‚РІРѕ РІРµСЂС€РёРЅ
        System.out.println("Number of ribs = " + m); //РєРѕР»РёС‡РµСЃС‚РІРѕ СЂРµР±РµСЂ
        beginning = new int[m];
        ending = new int[m];
        for (int i = 0; i < m; i++) {
            beginning[i] = sc.nextInt();
            ending[i] = sc.nextInt();
        }

        System.out.println();
        for (int i = 0; i < m; i++) {
            System.out.println(beginning[i] + " " + ending[i]);
        }
    }

    public void Output(String name, int[][] matrix) {
        System.out.println("\n" + name + ":");
        for (int i = 0; i < matrix.length; i++) {               //n СЃС‚СЂРѕРє - РІРµСЂС€РёРЅС‹
            for (int j = 0; j < matrix[0].length; j++) {           //m СЂСЏРґРєРѕРІ - СЂРµР±СЂР°
                if (matrix[i][j] != -1)
                    System.out.print(" " + matrix[i][j] + " ");
                else
                    System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static int[][] AdjacencyMatrix() {
        adjacencyMatrix = new int[n][n];

        for (int i = 0; i < m; i++) {
            adjacencyMatrix[ending[i] - 1][beginning[i] - 1] = 1;
        }
        return adjacencyMatrix;
    }

    public static int[][] IncidenceMatrix() {
        incidenceMatrix = new int[n][m];

        for (int i = 0; i < m; i++) {
            if (beginning[i] == ending[i])
                incidenceMatrix[beginning[i] - 1][i] = 2;
            else {
                incidenceMatrix[beginning[i] - 1][i] = -1;
                incidenceMatrix[ending[i] - 1][i] = 1;
            }
        }
        return incidenceMatrix;
    }

    public static void WriteFile(String name, int[][] matrix1) {
        try (FileWriter writer = new FileWriter(name, false)) {
            writer.write(name + "\n");
            for (int i = 0; i < matrix1.length; ++i) {
                for (int j = 0; j < matrix1[0].length; j++) {
                    if (matrix1[i][j] == -1) {
                        writer.write(Integer.toString(matrix1[i][j]) + " ");
                        writer.flush();
                    } else {
                        writer.write(" " + Integer.toString(matrix1[i][j]) + " ");
                        writer.flush();
                    }
                }
                writer.write("\n");
            }
        } catch (IOException e) {
            System.out.println("");
        }
        sc.close();
    }
}

package Laba1;

import java.io.*;
import java.util.Scanner;

import Laba1.WorkWithFile;

/**
 * Created by nelya on 23.02.16.
 */
public class mainClass {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Р’РІРµРґРёС‚Рµ РёРјСЏ С„Р°Р№Р»Р°: ");
        WorkWithFile file = new WorkWithFile(reader.readLine());
        file.ReadFile();

        System.out.println("\nР’С‹Р±РµСЂРёС‚Рµ РјР°С‚СЂРёС†Сѓ, РєРѕС‚РѕСЂСѓСЋ РЅСѓР¶РЅРѕ РїРѕСЃС‚СЂРѕРёС‚СЊ: \nСЃРјРµР¶РЅРѕСЃС‚Рё(РЅР°Р¶РјРёС‚Рµ 1)" +
                "\nРёРЅС†РёРґРµРЅС‚РЅРѕСЃС‚Рё (РЅР°Р¶РјРёС‚Рµ 2)");
        switch (Integer.parseInt(reader.readLine())) {
            case 1:
                int[][] adjacencyMatrix = file.AdjacencyMatrix();
                file.Output("РњР°С‚СЂРёС†Р° СЃРјРµР¶РЅРѕСЃС‚Рё", adjacencyMatrix);
                System.out.println("Р—Р°РїРёСЃР°С‚СЊ СЂРµР·СѓР»СЊС‚Р°С‚С‹ РІ С„Р°Р№Р»? Р•СЃР»Рё РґР°, РІРІРµРґРёС‚Рµ РёРјСЏ С„Р°Р№Р»Р°; РµСЃР»Рё РЅРµС‚ - РЅР°Р¶РјРёС‚Рµ Enter");
                String nameToWrite = reader.readLine();
                if (nameToWrite != "")
                    file.WriteFile(nameToWrite, adjacencyMatrix);
                break;
            case 2:
                int[][] incidenceMatrix = file.IncidenceMatrix();
                file.Output("РњР°С‚СЂРёС†Р° РёРЅС†РёРґРµРЅС‚РЅРѕСЃС‚Рё", incidenceMatrix);
                System.out.println("Р—Р°РїРёСЃР°С‚СЊ СЂРµР·СѓР»СЊС‚Р°С‚С‹ РІ С„Р°Р№Р»? Р•СЃР»Рё РґР°, РІРІРµРґРёС‚Рµ РёРјСЏ С„Р°Р№Р»Р°; РµСЃР»Рё РЅРµС‚ - РЅР°Р¶РјРёС‚Рµ Enter");
                nameToWrite = reader.readLine();
                if (nameToWrite != "")
                    file.WriteFile(nameToWrite, incidenceMatrix);
                break;
            default:
                System.out.println("РЅРµРІРµСЂРЅС‹Р№ РІРІРѕРґ");
                break;
        }
    }
}