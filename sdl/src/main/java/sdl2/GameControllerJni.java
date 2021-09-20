package sdl2;

public class GameControllerJni {

    private GameControllerJni() {}

    public static native void updateControllers();
    public static native int setEventState(int state);

    public static native int isGameController(int index);

    public static native long open(int index);
    public static native void close(long ptr);

    public static native int getAxis(long ptr, int index);
    public static native int getButton(long ptr, int index);
}
