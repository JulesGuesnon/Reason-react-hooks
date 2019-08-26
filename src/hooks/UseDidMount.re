let useDidMount = (cb: unit => unit) => {
  React.useEffect1(
    () => {
      cb();
      None;
    },
    [||],
  );
};