package Interface;

public class MultipleInterface {
    
    // Primo dettaglio:
    // In java una classe può estendere solo una classe, ma può estenderne molteplici:

    public enum Color {BLACK, WHITE, YELLOW, RED, GREEN}

    public interface IColorable {
        public Color getColor();
        public void setColor(Color c);
    }

    public class Rectangle implements IShape, IColorable {
        //variabili e costruttore omessi
        
        @Override
        public double getArea() { return s1 * s2; }
        
        @Override
        public double getPerimeter() { return (s1 + s2) * 2; }
        
        @Override
        public Color getColor() { return this.c; }
        
        @Override
        public void setColor(Color c) { this.c = c; }
        // ...
    }

}
