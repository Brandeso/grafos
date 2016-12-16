/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import static java.lang.System.exit;
import java.util.Scanner;
/**
 *
 * @author Br14
 */
public class Adyacencia 
{
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Scanner entrada = new Scanner(System.in);
        // TODO code application logic here
        
        int[][] matriz = new int[10][10];
        //int[][] matriz[10][10];
        int a, b, c;
        
        for(a = 0; a < 10; a++)
        {
            for(b = 0; b < 10; b++)
            {
                matriz[a][b] = 0;
            }
        }
        
        System.out.println("Introduzca los valores de la matriz de adyacencia");
        
        for(a = 0; a < 10; a++)
        {
            for(b = 0; b < 10; b++)
            {
                if(a == b)
                {
                    System.out.println("Es el punto (" + (a+1) + "," + (b+1) + "), no se permiten bucles.");
                    break;
                }
                System.out.print("Introduzca el valor del punto (" + (a+1) + "," + (b+1) + ") : ");
                matriz[a][b] = entrada.nextInt();
                if((matriz[a][b] != 0) && (matriz[a][b] != 1))
                {
                    System.out.println("Error, los valores de la matriz no pueden ser diferentes a 0 ó 1");
                    exit(1);
                }
                matriz[b][a] = matriz[a][b];
            }
        }
        
        System.out.println("\nLa matriz de adyacencia es: ");
        
        for(a = 0; a < 10; a++)
        {
            for(b = 0; b < 10; b++)
            {
                if(b != 9)
                {
                    System.out.print(matriz[a][b] + "  ");
                }
                else
                {
                    System.out.print(matriz[a][b]);
                }
            }
            System.out.print("\n");
        }
    }   
}