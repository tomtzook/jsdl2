package sdl2;

public class SdlJni {

    private SdlJni() {}

    public static native int init0(int flags);
    public static native void quit();

    public static native String getError();
}
