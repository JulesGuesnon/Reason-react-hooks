let prevTimeoutId = ref(None);

let useDebounce = (~cb, ~delay=100, ()) => {
  switch (prevTimeoutId^) {
  | Some(id) => id->Js.Global.clearTimeout
  | None => ()
  };

  prevTimeoutId := Some(Js.Global.setTimeout(() => cb(), delay));
};