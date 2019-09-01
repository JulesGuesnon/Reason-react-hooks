let useDebounce = (~cb, ~delay, ()) => {
  let prevTimeoutId = ref(None);

  param => {
    switch (prevTimeoutId^) {
    | Some(id) => id->Js.Global.clearTimeout
    | None => ()
    };

    prevTimeoutId := Some(Js.Global.setTimeout(() => cb(param), delay));
  };
};