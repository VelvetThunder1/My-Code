public class RightTriangle {
    public static void main(String[] args) {
        int sidea = Integer.parseInt(args[0]);
        int sideb = Integer.parseInt(args[1]);
        int sidec = Integer.parseInt(args[2]);
        int a2 = (sidea)*(sidea);
        int b2 = (sideb)*(sideb);
        int c2 = (sidec)*(sidec);
        boolean isPositive = (sidea > 0) && (sideb > 0) && (sidec > 0);
        boolean isSquare = (a2 + b2 == c2) || (b2 + c2 == a2) || (a2 + c2 == b2);
        System.out.println(isPositive && isSquare);
    }
}