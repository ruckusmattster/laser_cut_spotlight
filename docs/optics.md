# Optics

## Positioning the LED

The thin lens equation:

```
1/f = 1/u + 1/v
```

- `f`: focal length of the lens (70 mm here)
- `u`: distance from the source (LED) to the lens
- `v`: distance from the lens to the smallest point of the beam

**Sunlight through a lens.** The source is effectively infinitely far away, so `u → ∞` and `1/u = 0`. That leaves `f = v`: parallel rays are bent to a point at the focal length.

**A spotlight wants the opposite.** We treat the LED as a point source and want the output collimated, so `v → ∞`. That gives `1/f = 1/u`, which means `u = f`.

**Put the LED exactly one focal length from the lens.** If it sits further away, the beam converges to a point in front of the lens, and that point moves towards the lens the further the LED is moved. If it sits closer, the beam diverges.

## Focus sensitivity

A spacing change of just **1.6 mm** makes a visible difference. When the spacing is off, the beam converges to a waist and then diverges. When it's close to correct, a slight convergence and divergence is still visible, because this build is limited by the thinnest shim available.

The easiest way to check focus is in a dark room with fog or haze. As you move the LED, you can watch the beam's narrowest point move.

## Choosing a lens
- A 200 mm diameter lens with a 70 mm focal length captures most of the SFT-42R's output.
- A longer focal length also works, but the lens will collect a smaller share of the LED's light.
