package sdl2;

public class GameControllerJni {

    private GameControllerJni() {}

    public static native long open(int index);
    public static native void close(long ptr);

}
