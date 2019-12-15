import java.util.*;
public class EvenUp {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt();
        Stack<Integer> cards = new Stack<Integer>();
        Stack<Integer> stored = new Stack<Integer>();
        for(int i = 0; i<n; i++) {
            int a = io.getInt();
            cards.push(a);
        }
        int ans = 0;
        while(!cards.isEmpty()) {
            int x = cards.pop();
            if(x % 2 == 0) {
                if(cards.isEmpty()) {
                    if(stored.isEmpty()) {
                        stored.push(x);
                    } else {
                        int z = stored.peek();
                        if(z % 2 != 0) {
                            stored.push(x);
                        } else {
                            stored.pop();
                        }
                    }
                } else {
                    int y = cards.peek();
                    if(y % 2 != 0) {
                        if(stored.isEmpty()) {
                            stored.push(x);
                        } else {
                            int z = stored.peek();
                            if(z % 2 != 0) {
                                stored.push(x);
                            } else {
                                stored.pop();
                            }
                        }
                    } else {
                        cards.pop();
                    }
                }
            } else {
                if(cards.isEmpty()) {
                    if(stored.isEmpty()) {
                        stored.push(x);
                    } else {
                        int z = stored.peek();
                        if(z % 2 == 0) {
                            stored.push(x);
                        } else {
                            stored.pop();
                        }
                    }
                } else {
                    int y = cards.peek();
                    if(y % 2 == 0) {
                        if(stored.isEmpty()) {
                            stored.push(x);
                        } else {
                            int z = stored.peek();
                            if(z % 2 == 0) {
                                stored.push(x);
                            } else {
                                stored.pop();
                            }
                        }
                    } else {
                        cards.pop();
                    }
                }
            }
        }
        while(!stored.isEmpty()) {
            ans += 1;
            stored.pop();
        }
        io.println(ans);
        io.flush();
    }
}