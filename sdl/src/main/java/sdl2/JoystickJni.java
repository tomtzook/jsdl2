package sdl2;

public class JoystickJni {

    private JoystickJni() {}

    public static native long open(int index);
    public static native void close(long ptr);

    public static native int getNumAxes(long ptr);
    public static native int getNumButtons(long ptr);
    public static native int getNumHats(long ptr);
    public static native int getNumBalls(long ptr);
}
