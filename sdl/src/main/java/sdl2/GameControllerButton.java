package sdl2;

public enum GameControllerButton {
    A(0),
    B(1),
    X(2),
    Y(3),
    BACK(4),
    GUIDE(5),
    START(6),
    LEFT_STICK(7),
    RIGHT_STICK(8),
    DPAD_UP(9),
    DPAD_DOWN(10),
    DPAD_LEFT(11),
    DPAD_RIGHT(12)
    ;

    private final int mIndex;

    GameControllerButton(int index) {
        mIndex = index;
    }

    public int index() {
        return mIndex;
    }
}
