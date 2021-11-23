public class GreatCircle {
    public static void main(String[] args) {
        double x1 = Math.toRadians(Double.parseDouble(args[0]));
        double y1 = Math.toRadians(Double.parseDouble(args[1]));
        double x2 = Math.toRadians(Double.parseDouble(args[2]));
        double y2 = Math.toRadians(Double.parseDouble(args[3]));
        double a = ((x2-x1)/2);
        double b = ((y2-y1)/2);
        double sina2 = ((Math.sin(a))*(Math.sin(a)));
        double sinb2 = ((Math.sin(b))*(Math.sin(b)));
        double c = ((Math.cos(x1))*((Math.cos(x2)))*sinb2);
        double d = (Math.sqrt(sina2+c));
        double e = (2*6371.0*(Math.asin(d)));
        System.out.println(e + " kilometers");
    }
}