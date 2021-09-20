package sdl2;

public class JoystickJni {

    public static final int AXIS_MAX = 32767;
    public static final int AXIS_MIN = -32768;

    public static final int HAT_CENTERED = 0x00;
    public static final int HAT_UP = 0x01;
    public static final int HAT_RIGHT = 0x02;
    public static final int HAT_DOWN = 0x04;
    public static final int HAT_LEFT = 0x08;

    private JoystickJni() {}

    public static native int getNumJoysticks();
    public static native void updateJoysticks();
    public static native int setEventState(int state);

    public static native int getDeviceType(int index);
    public static native int getDeviceInstanceId(int index);

    public static native long open(int index);
    public static native void close(long ptr);
    public static native long fromInstanceId(int id);

    public static native String getName(long ptr);
    public static native int getType(long ptr);
    public static native int getInstanceId(long ptr);

    public static native int getNumAxes(long ptr);
    public static native int getNumButtons(long ptr);
    public static native int getNumHats(long ptr);
    public static native int getNumBalls(long ptr);

    public static native int getAxis(long ptr, int index);
    public static native int getButton(long ptr, int index);
    public static native int geHat(long ptr, int index);
    public static native long getBall(long ptr, int index);
}
