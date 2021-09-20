package sdl2.events;

public class JDeviceConnectionEvent extends Event {

    private final int mDeviceIndex;
    private final boolean mIsConnected;

    public JDeviceConnectionEvent(int deviceIndex, boolean isConnected) {
        super(isConnected ? EventType.JOY_DEVICE_ADDED : EventType.JOY_DEVICE_REMOVED);
        mDeviceIndex = deviceIndex;
        mIsConnected = isConnected;
    }

    public int getDeviceIndex() {
        return mDeviceIndex;
    }

    public boolean isConnected() {
        return mIsConnected;
    }
}
