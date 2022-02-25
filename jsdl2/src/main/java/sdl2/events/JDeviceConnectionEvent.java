package sdl2.events;

public class JDeviceConnectionEvent extends Event {

    private final int mWhich;
    private final boolean mIsConnected;

    public JDeviceConnectionEvent(int which, boolean isConnected) {
        super(isConnected ? EventType.JOY_DEVICE_ADDED : EventType.JOY_DEVICE_REMOVED);
        mWhich = which;
        mIsConnected = isConnected;
    }

    /**
     * <p>
     *     When {@link #isConnected()} is <code>true</code>, returns
     *     the index for the newly connected device. To retrieve the joystick,
     *     use
     *     <pre>
     *         long ptr = SDLJoystick.open(event.getWhich());
     *         int id = SDLJoystick.getInstanceId(ptr);
     *     </pre>
     * </p>
     * <p>
     *     When {@link #isConnected()} is <code>false</code>, returns
     *     the <em>ID</em> of the device.
     * </p>
     * @return <em>index</em> or <em>ID</em> of the device.
     */
    public int getWhich() {
        return mWhich;
    }

    public boolean isConnected() {
        return mIsConnected;
    }
}
