public class threesort {
    public static void main(String[] args){
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        int c = Integer.parseInt(args[2]);
        int ab = Math.max(a,b);
        int max = Math.max(ab,c);
        int ba = Math.min(a,b);
        int min = Math.min(ba,c);
        int middle = ((a+b+c)-(max+min));
        System.out.println(max);
        System.out.println(middle);
        System.out.println(min);
    }
}