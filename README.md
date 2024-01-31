<div align="center">
<img width="60%" src="images/banner.png"></img>
<hr>
<p>colourise text based on string pattern</p>
</div>

# What does it do

Colourise any text stream with custom colours easily with string patterns

# How to use colorizer

The program will look for strings specified after arguments like --after --from and --reset-on and format them to the colour specified after. For example:

```bash
stat image.png | clr red --after ": " green --reset-on "  "
```

This will output the stdin in `red`. However, after encountering `": "` it will format the string to become `green`. Then it will again be reset to red after two consecutive spaces `"  "`.

By default definition of the colours if read from `~/.config/colourizer/preset`
