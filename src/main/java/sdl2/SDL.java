package sdl2;

/**
 * Functions for general SDL usage.
 */
public class SDL {

    public static final int INIT_TIMER = 0x00000001;
    public static final int INIT_AUDIO = 0x00000010;
    public static final int INIT_VIDEO = 0x00000020;
    public static final int INIT_JOYSTICK = 0x00000200;
    public static final int INIT_HAPTIC = 0x00001000;
    public static final int INIT_GAMECONTROLLER = 0x00002000;
    public static final int INIT_EVENTS = 0x00004000;
    public static final int INIT_SENSOR = 0x00008000;
    public static final int INIT_NOPARACHUTE = 0x00100000;

    private SDL() {}

    /**
     * Initializes SDL. Must be called before any other use.
     *
     * @param flags initialization flags indicating subsystems.
     * @return 0 on success, negative value on error.
     */
    public static native int init(int flags);

    /**
     * Cleans up all initialized subsystems. Should be called
     * on all exit conditions.
     */
    public static native void quit();

    /**
     * Gets a description for the latest error caused by an SDL
     * library call.
     *
     * @return description, or null if no error.
     */
    public static native String getError();
}
