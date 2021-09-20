package sdl2;

public class SdlJni {

    public static final int INIT_TIMER = 0x00000001;
    public static final int INIT_AUDIO = 0x00000010;
    public static final int INIT_VIDEO = 0x00000020;
    public static final int INIT_JOYSTICK = 0x00000200;
    public static final int INIT_HAPTIC = 0x00001000;
    public static final int INIT_GAMECONTROLLER = 0x00002000;
    public static final int INIT_EVENTS = 0x00004000;
    public static final int INIT_SENSOR = 0x00008000;
    public static final int INIT_NOPARACHUTE = 0x00100000;

    public static final int EVENT_STATE_QUERY = -1;
    public static final int EVENT_STATE_IGNORE = 0;
    public static final int EVENT_STATE_DISABLE = 0;
    public static final int EVENT_STATE_ENABLE = 1;

    private SdlJni() {}

    public static native int init(int flags);
    public static native void quit();

    public static native String getError();
}
