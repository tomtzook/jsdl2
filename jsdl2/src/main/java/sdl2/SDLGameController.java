package sdl2;

public class SDLGameController {

    public static final int AXIS_MAX = 32767;
    public static final int AXIS_MIN = -32768;

    public enum AxisType {
        LEFT_X,
        LEFT_Y,
        RIGHT_X,
        RIGHT_Y,
        TRIGGER_LEFT,
        TRIGGER_RIGHT
    }

    public enum ButtonType {
        A,
        B,
        X,
        Y,
        BACK,
        GUIDE,
        START,
        LEFT_STICK,
        RIGHT_STICK,
        LEFT_SHOULDER,
        RIGHT_SHOULDER,
        DPAD_UP,
        DPAD_DOWN,
        DPAD_LEFT,
        DPAD_RIGHT
    }

    private SDLGameController() {}

    /**
     * Manually updates the values of open controllers.
     */
    public static native void updateGameControllers();

    /**
     * Sets the current event handling state for the game controller subsystem.
     * <p>
     *     If enabled, use {@link SDLEvents} to poll for events and handle changes.
     *     If disabled, manually call {@link #updateGameControllers()} to update for changes
     *     to open controllers.
     * </p>
     *
     * @param enabled <b>true</b> to enable, <b>false</b> other.
     */
    public static native void setEventPolling(boolean enabled);

    /**
     * Gets whether or not event polling is enabled.
     * <p>
     *     If enabled, use {@link SDLEvents} to poll for events and handle changes.
     *     If disabled, manually call {@link #updateGameControllers()} to update for changes
     *     to open game controllers.
     * </p>
     *
     * @return <b>true</b> if enabled, <b>false</b> if disabled.
     */
    public static native boolean isEventPolling();

    /**
     * Gets whether the given device is a game controller.
     * @param index a device index as used for the joystick subsystem.
     * @return <b>true</b> if the device is a game controller and can
     *      be used with this subsystem, <b>false</b> otherwise.
     */
    public static native boolean isGameController(int index);

    /**
     * Opens a connected device.
     *
     * @param device index indicating the device.
     * @return a pointer to the device structure.
     */
    public static native long open(int device);

    /**
     * Closes an open device.
     *
     * @param ptr a pointer to the device structure.
     */
    public static native void close(long ptr);

    /**
     * Gets an open device.
     *
     * @param id id of the device to get.
     * @return a pointer to the device structure.
     */
    public static native long fromInstanceId(int id);

    /**
     * Gets the underlying joystick object associated with the device.
     *
     * @param ptr a pointer to the device structure.
     * @return a pointer to the joystick device structure.
     */
    public static native long getJoystick(long ptr);

    /**
     * Gets the value of an axis on an open device.
     *
     * @param ptr a pointer to the device structure.
     * @param axis axis to retrieve.
     * @return value of axis between {@value #AXIS_MIN} and {@value #AXIS_MAX} for
     *      a normal axis. For trigger axes, between <em>0</em> and {@value #AXIS_MAX}
     *      or 0 on error.
     */
    public static native int getAxis(long ptr, AxisType axis);

    /**
     * Gets the value of an button on an open device.
     *
     * @param ptr a pointer to the device structure.
     * @param button button to retrieve.
     * @return <b>true</b> if pressed, <b>false</b> otherwise.
     */
    public static native boolean getButton(long ptr, ButtonType button);
}
