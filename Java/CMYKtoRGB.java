public class CMYKtoRGB {
    public static void main(String[] args) {
        int cyan = Integer.parseInt(args[0]);
        int magenta = Integer.parseInt(args[1]);
        int yellow = Integer.parseInt(args[2]);
        int black = Integer.parseInt(args[3]);
        int white = 1 - black;
        int red1 = 255*(white)*(1-cyan);
        int green1 = 255*(white)*(1-magenta);
        int blue1 = 255*(white)*(1-yellow);
        System.out.println("red   = " + red1);
        System.out.println("green = " + green1);
        System.out.println("blue  = " + blue1);
    }
}