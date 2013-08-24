package equationsgrad2;

import java.util.Scanner;

/**
 *
 * @author realidadvirtual
 */
public class EquationsGrad2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int a, b, c;
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Ingrese el valor de a, b y c separados por espacios:");
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        
        if(a == 0){
            System.out.println("No quadratic equation to solve");
            return;
        }
        
        System.out.println(a+"x^2 "+b+"x "+c);
        
        int min, max;
        
        System.out.println("Ingrese el intervalo a revisar:");
        min = sc.nextInt();
        max = sc.nextInt();
        
        System.out.println("["+min+", "+max+"]");
        for (int x = min; x <= max; x++) {
            int y = a*(x*x) + b*x + c;
            if(y == 0){
                System.out.println(x);
            }
        }
    }
}
