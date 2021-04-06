package Interface;

public class ParameterInterface {
    
    // Secondo dettaglio:
    // Classe Interface come tipo
    
    private static void colorWhite (IColorable s) {    // <-- Classe Interface usata come parametro
        s.setColor(Color.WHITE);
    }

    public static void main (String[] args) {
        Rectangle rect1 = new Rectangle(2, 3);
        Circle circle1 = new Circle(5);
        colorWhite(rect1);		                       // Ok se entrambe le classi implementano IColorable
        colorWhite(circle1);		                   // Ok se entrambe le classi implementano IColorable
    }
}




