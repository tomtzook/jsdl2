package sdl2.events;

public class CDeviceConnectionEvent extends Event {

    private final int mDeviceIndex;
    private final boolean mIsConnected;

    public CDeviceConnectionEvent(int deviceIndex, boolean isConnected) {
        super(isConnected ? EventType.CONTROLLER_DEVICE_ADDED : EventType.CONTROLLER_DEVICE_REMOVED);
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
