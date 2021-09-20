package sdl2.events;

public class DeviceConnectionEvent extends Event {

    private final int mDeviceIndex;
    private final boolean mIsConnected;

    public DeviceConnectionEvent(int type, int deviceIndex, boolean isConnected) {
        super(type);
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
