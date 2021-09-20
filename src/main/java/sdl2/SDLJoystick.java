package sdl2;

/**
 * Allows usage of the SDL Joystick subsystem.
 */
public class SDLJoystick {

    public static final int AXIS_MAX = 32767;
    public static final int AXIS_MIN = -32768;

    public static final int HAT_CENTERED = 0x00;
    public static final int HAT_UP = 0x01;
    public static final int HAT_RIGHT = 0x02;
    public static final int HAT_DOWN = 0x04;
    public static final int HAT_LEFT = 0x08;
    public static final int HAT_UP_RIGHT = HAT_UP | HAT_RIGHT;
    public static final int HAT_UP_LEFT = HAT_UP | HAT_LEFT;
    public static final int HAT_DOWN_RIGHT = HAT_DOWN | HAT_RIGHT;
    public static final int HAT_DOWN_LEFT = HAT_DOWN | HAT_LEFT;

    private SDLJoystick() {}

    /**
     * Gets the amount of connected joysticks.
     *
     * @return amount of connected joysticks, or negative value on error.
     */
    public static native int getNumJoysticks();

    /**
     * Manually updates the values of open joysticks.
     */
    public static native void updateJoysticks();

    /**
     * Sets the current event handling state for the joystick subsystem.
     * <p>
     *     If enabled, use {@link SDLEvents} to poll for events and handle changes.
     *     If disabled, manually call {@link #updateJoysticks()} to update for changes
     *     to open joysticks.
     * </p>
     *
     * @param enabled <b>true</b> to enable, <b>false</b> other
     * @return negative value on error, 0 on success.
     */
    public static native int setEventPolling(boolean enabled);

    /**
     * Gets whether or not event polling is enabled.
     * <p>
     *     If enabled, use {@link SDLEvents} to poll for events and handle changes.
     *     If disabled, manually call {@link #updateJoysticks()} to update for changes
     *     to open joysticks.
     * </p>
     *
     * @return 1 if enabled, 0 if disabled, negative value on error.
     */
    public static native int isEventPolling();

    /**
     * Get the type of a connected device.
     *
     * @param device index indicating the device.
     * @return an integer value indicating the type. Use
     *      {@link JoystickType#fromRaw(int)} to get the enum value.
     */
    public static native int getDeviceType(int device);

    /**
     * Get the instance id of a connected device.
     *
     * @param device index indicating the device.
     * @return id which will indicate the device, or -1 on error.
     */
    public static native int getDeviceInstanceId(int device);

    /**
     * Opens a connected device.
     *
     * @param device index indicating the device.
     * @return a pointer to the device structure, or 0 on error.
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
     * @return a pointer to the device structure, or 0 on error.
     */
    public static native long fromInstanceId(int id);

    /**
     * Gets the name of the device.
     *
     * @param ptr a pointer to the device structure.
     * @return name of the device, or null on error.
     */
    public static native String getName(long ptr);

    /**
     * Gets the type of the open device.
     *
     * @param ptr a pointer to the device structure.
     * @return an integer value indicating the type. Use
     *    {@link JoystickType#fromRaw(int)} to get the enum value.
     */
    public static native int getType(long ptr);

    /**
     * Gets the id associated with an open device.
     *
     * @param ptr a pointer to the device structure.
     * @return id for the device.
     */
    public static native int getInstanceId(long ptr);

    /**
     * Gets the amount of axes on an open device.
     *
     * @param ptr a pointer to the device structure.
     * @return amount of axes, or negative value on error.
     */
    public static native int getNumAxes(long ptr);

    /**
     * Gets the amount of buttons on an open device.
     *
     * @param ptr a pointer to the device structure.
     * @return amount of buttons, or negative value on error.
     */
    public static native int getNumButtons(long ptr);

    /**
     * Gets the amount of hats on an open device.
     *
     * @param ptr a pointer to the device structure.
     * @return amount of hats, or negative value on error.
     */
    public static native int getNumHats(long ptr);

    /**
     * Gets the amount of balls on an open device.
     *
     * @param ptr a pointer to the device structure.
     * @return amount of balls, or negative value on error.
     */
    public static native int getNumBalls(long ptr);

    /**
     * Gets the value of an axis on an open device.
     *
     * @param ptr a pointer to the device structure.
     * @param index index of the axis, between 0 and {@link #getNumAxes(long)}
     * @return value of axis between {@value #AXIS_MIN} and {@value #AXIS_MAX},
     *      or 0 on error.
     */
    public static native int getAxis(long ptr, int index);

    /**
     * Gets the value of an button on an open device.
     *
     * @param ptr a pointer to the device structure.
     * @param index index of the button, between 0 and {@link #getNumButtons(long)}.
     * @return 1 if pressed, 0 if not pressed.
     */
    public static native int getButton(long ptr, int index);

    /**
     * Gets the value of an hat on an open device.
     *
     * @param ptr a pointer to the device structure.
     * @param index index of the hat, between 0 and {@link #getNumHats(long)}.
     * @return value of hat, one of
     *  <ul>
     *      <li>{@link #HAT_CENTERED}</li>
     *      <li>{@link #HAT_UP}</li>
     *      <li>{@link #HAT_RIGHT}</li>
     *      <li>{@link #HAT_DOWN}</li>
     *      <li>{@link #HAT_LEFT}</li>
     *      <li>{@link #HAT_UP_RIGHT}</li>
     *      <li>{@link #HAT_UP_LEFT}</li>
     *      <li>{@link #HAT_DOWN_RIGHT}</li>
     *      <li>{@link #HAT_DOWN_LEFT}</li>
     *  </ul>
     */
    public static native int getHat(long ptr, int index);

    /**
     * Gets the value of an ball on an open device.
     *
     * @param ptr a pointer to the device structure.
     * @param index index of the ball, between 0 and {@link #getNumBalls(long)}.
     * @return value of ball made up of 2 integers:
     *  <ul>
     *      <li>dx = value &amp; 0xff</li>
     *      <li>dy = (value &gt;&gt; 4) &amp; 0xff</li>
     *  </ul>
     *  These values indicate the differences in values since last poll.
     */
    public static native long getBall(long ptr, int index);
}
