package eq2;

/**
 * Receives two quadratic equations and solves them for intercepts.
 * @author halzate93
 */
public class Eq2Solver {

    /**
     * @param args the command line arguments.
     * Contains both equations parameters and
     * the range to be evaluated on.
     * 
     * The order of the 8 parameters is:
     * {a, b, c, d, e, f, m, n}
     *  0  1  2  3  4  5  6  7
     */
    
    public static void main(String[] args) throws Exception {
        if(args.length != 8){
            throw new Exception("Invalid args");
        }
        //First equation
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        int c = Integer.parseInt(args[2]);
        if(a == 0){
            throw new Exception("a can't be zero");
        }
        
        //Second equation
        int d = Integer.parseInt(args[3]);
        int e = Integer.parseInt(args[4]);
        int f = Integer.parseInt(args[5]);
        if(d == 0){
            throw new Exception("d can't be zero");
        }
        
        //Interval
        int m = Integer.parseInt(args[6]);
        int n = Integer.parseInt(args[7]);
        if(m > n){
            throw new Exception("m must be less or equal to n");
        }
        
        Grapher g = new Grapher(m, n);
        
        //The number of interceptions, It can only take values of 0, 1, 2 or (n-m)+1
        int cont = 0;
        
        for (int x = m; x <= n; x++) {
            int y1 = a*x*x + b*x + c;
            int y2 = d*x*x + e*x + f;
            
            if(y1 == y2){   //Found an interception
                cont++;
                System.out.println("("+x+", "+y1+")");
                g.addPoint(x, y2, true);
            }else{
                g.addPoint(x, y1, false);
                g.addPoint(x, y2, false);
            }
        }
        
        switch(cont){
            case 0:
                System.out.println("No interception found");
                break;
            case 1:
            case 2:
                System.out.println(cont+" interceptions found");
                break;
            default:
                System.out.println("The equations are equal");
        }
        
        g.drawGraph();
        System.in.read();
        System.exit(0);
    }
}
