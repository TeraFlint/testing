export module p3.testing;

export import p3.testing.run;
export import p3.testing.assert;

/*  Module structure:         +-----------------------------+
                          +---| p3.testing.unit_test        |<--+
  +-------------------+   |   +-----------------------------+   |
  | p3.testing.core   |<--+---| p3.testing.property_test    |<--+
  +-------------------+   |   +-----------------------------+   |
                          +---| p3.testing.performance_test |<--+
                              +-----------------------------+   |
                                                                |
  +-------------------+   +------------+   +----------------+   |
  | p3.testing.assert |-->| p3.testing |<--| p3.testing.run |---+
  +-------------------+   +------------+   +----------------+
                                 ^
  +-------------------+          |       \
  | main / entry      |----------+        |
  +-------------------+          |        |
  | test module 1     |----------+        |      user-defined modules,
  +-------------------+          |        |      names don't matter.
  | test module 2     |----------+         >
  +-------------------+          |        |      test modules contain
    ...                          |        |      test structures.
  +-------------------+          |        |      no need to import these.
  | test module n     |----------+        |
  +-------------------+                 */
