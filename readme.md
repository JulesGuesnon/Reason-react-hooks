# Reason-react-hooks

this package is a group of various hooks for reason-react that you may want to use.

## How to install ?

```bash
npm install reason-react-hooks --save
```

```bash
yarn add reason-react-hooks
```

Then add the dependency to you `bsconfig.json`

```json
"bs-dependencies": [
	"reason-react-hooks"
],
```

## How to use it ?

### What the package contains ?

All the hooks are located under `ReasonReactHooks.Hooks`

:rotating_light: **Don't use any other module,** for now bucklescript private module system isn't working but when it will, only `ReasonReactHooks.Hooks` will be expose.

## Examples

### useVisible

This hook allow you to detect when an element appear on the screen.
**It will trigger every time the element enter the window**, which mean if the element is visible, then not, and visible again, the callback will trigger **2 times**.

```reason
[@react.component]
let make = () => {
  let (ref, isVisible) = ReasonReactHooks.Hooks.useVisible();

  <div ref>
    {
        isVisible ? "Hello !" : "I'm hidden";
    }
    ->ReasonReact.string
  </div>;
};
```

### useHover

This hook allow you to know when an element is hovered.

```reason
[@react.component]
let make = () => {
  let (ref, isHover) = ReasonReactHooks.Hooks.useHover();

  <div ref>
    {
      isHover ? "You're on me !" : "You're not on me !";
    }
    ->ReasonReact.string
  </div>;
};
```

### useDidMount

This hook allow you to do same that with classes and trigger a callback once the component is mounted

```reason
[@react.component]
let make = () => {
  ReasonReactHooks.Hooks.useDidMount(~cb=() => Js.log("Component mounted"));

  <div> "Hello world"->ReasonReact.string </div>;
};
```

### useDebounce

This hook allow you to debounce a function. It's pretty useful to deal with input and for performances
**You can only pass 1 parameter to you callback.** If you need more that 1 parameter, consider using an array, a record, a dict...

```reason
[@react.component]
let make = () => {
  let (_, setValue) = React.useState(_ => "");
  let debouncedFunction =
    ReasonReactHooks.Hooks.useDebounce(
      ~cb=
        value => {
          setValue(_ => value);
          Js.log(value);
        },
      ~delay=500,
      (),
    );
  <div>
    <input
      type_="text"
      onChange={e => {
        let value = ReactEvent.Form.target(e)##value;
        debouncedFunction(value);
      }}
    />
  </div>;
};
```

### useWindowSize

This hook allow you to get the window height and width.
**It handle the window resize**

```reason
[@react.component]
let make = () => {
  let windowSize = ReasonReactHooks.Hooks.useWindowSize();
  let height = windowSize.height;
  let width = windowSize.width;
  <div>
    {j| The window is currently $width x $height|j}->ReasonReact.string
  </div>;
};
```
