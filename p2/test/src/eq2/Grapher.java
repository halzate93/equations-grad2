package eq2;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import javax.swing.JFrame;

/**
 *
 * @author halzate93
 */
public class Grapher extends JFrame{
    
    private BufferedImage graph;
    private ArrayList<Point> points, intercepts;
    private int maxY = 0, minY = 0, domain, range;
    private boolean done = false;
    
    public Grapher(int domain) {
        this.domain = domain;
        this.setTitle("Eq2Solver");
        this.setVisible(true);
        this.setResizable(false);
        
        points = new ArrayList<>(domain);
        intercepts = new ArrayList<>(2);
        
        graph = new BufferedImage(getWidth(), getHeight(), BufferedImage.BITMASK);
    }
    
    /**
     * Adds the point to the graph, this must be done before actually drawing
     * because we need to know the highest and the lowest value of y.
     * @param x
     * @param y
     * @param intercept true if the point is an intercept, false otherwise.
     */
    public void addPoint(int x, int y, boolean intercept){
        if(done) return;
        
        Point p =new Point(x, y);
       
        if(y > maxY){
            maxY = y;
        }else{
            if(y < minY){
                minY = y;
            }
        }
        
        if(intercept){
            intercepts.add(p);
        }else{
            points.add(p);
        }
    }
    
    /**
     * Actually draws the graph according to the points added this far, no more
     * points can be add after this.
     */
    public void drawGraph(){
        done = true;
        range = maxY - minY;
        int dx = getWidth()+2/domain; //+2 for margin of the graph
        int dy = getHeight()+2/range;
        
        Graphics2D g2d = (Graphics2D)graph.getGraphics();
        
        //Regular points
        g2d.setColor(Color.black);
        for (int i = 0; i < points.size(); i++) {
            Point p = points.get(i);
            g2d.drawString("("+p.x+", "+p.y+")", p.x+1*dx, p.y+1*dy); //+1 for margin
        }
        
        //Intercepts
        g2d.setColor(Color.red);
        for (int i = 0; i < intercepts.size(); i++) {
            Point p = intercepts.get(i);
            g2d.drawString("("+p.x+", "+p.y+")", p.x+1*dx, p.y+1*dy); //+1 for margin
        }
        
        g2d.dispose();
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        ((Graphics2D)g).drawImage(graph, 0, 0, getWidth(), getHeight(), this);
        g.dispose();
    }
}
